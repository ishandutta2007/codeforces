#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=1.1e6;

struct Range{
	LL l,r;
};

struct DS{
	Range q[N+N];
	Range qaq;
	int sgn;
	LL add;

	struct Edit{
		int pos;
		Range value;
	};
	vector<Edit> edits;
	struct Ver{
		int editVer;
		Range qaq;
		int sgn;
		LL add;
	};
	vector<Ver> vers;

	void commit(){
		vers.push_back((Ver){(int)edits.size(),qaq,sgn,add});
	}
	void revert(){
		Ver v=vers.back();
		vers.pop_back();
		R(i,(int)edits.size()-1,v.editVer){
			Edit e=edits[i];
			q[e.pos]=e.value;
		}
		edits.resize(v.editVer);
		qaq=v.qaq;
		sgn=v.sgn;
		add=v.add;
	}
	void set(int pos,Range v){
		edits.push_back((Edit){pos,q[pos]});
		q[pos]=v;
	}

	DS(){
		clear();
	}
	void clear(){
		qaq=(Range){N,N-1};
		sgn=1;
		add=0;
	}
	void push_back(Range w){
		qaq.r++;
		set(qaq.r,w);
	}
	void push_front(Range w){
		qaq.l--;
		set(qaq.l,w);
	}
	void pop_back(){
		qaq.r--;
	}
	void pop_front(){
		qaq.l++;
	}
	bool empty()const{
		return qaq.l>qaq.r;
	}

	void flip(LL w){
		add=w-add;
		sgn*=-1;
	}
	LL f(LL r)const{
		return sgn*r+add;
	}
	LL unf(LL x)const{
		return (x-add)*sgn;
	}
	Range f(Range rg)const{
		return sgn==1?(Range){f(rg.l),f(rg.r)}:(Range){f(rg.r),f(rg.l)};
	}
	Range unf(Range rg)const{
		return sgn==1?(Range){unf(rg.l),unf(rg.r)}:(Range){unf(rg.r),unf(rg.l)};
	}
	void push(Range rg){
		if(sgn==1)push_back(unf(rg));
		else push_front(unf(rg));
	}
	void push(LL l,LL r){
		push((Range){l,r});
	}
	Range top()const{
		return f(sgn==1?q[qaq.r]:q[qaq.l]);
	}
	void pop(){
		if(sgn==1)pop_back();
		else pop_front();
	}
};

DS st;

ostream &operator<<(ostream &o,Range rg){
	return o<<"["<<rg.l<<","<<rg.r<<"]";
}
ostream &operator<<(ostream &o,DS &ds){
	ds.commit();
	stack<Range> rgs;
	while(!ds.empty()){
		rgs.push(ds.top());
		ds.pop();
	}
	ds.revert();
	o<<"{";
	while(!rgs.empty()){
		o<<rgs.top();
		rgs.pop();
		if(!rgs.empty())o<<" ";
	}
	return o<<"}";
}

int sgn(LL x){
	return x>0?1:-1;
}

LL w[N];
LL d[N];
LL a[N];
int main(){
	int n=read();
	read();
	F(i,1,n-2)w[i]=read();
	// reverse(w+1,w+n-1);
	st.clear();
	st.push(0,w[1]);
	// cerr<<"d[1] in "<<st<<endl;
	F(i,1,n-2){
		// cerr<<"w["<<i<<"]="<<w[i]<<endl;
		while(!st.empty()){
			Range rg=st.top();
			if(rg.r<w[i])break;
			else if(rg.l>w[i]){
				st.pop();
			}
			else{
				st.pop();
				st.push(rg.l,w[i]);
				break;
			}
		}
		st.commit();
		if(st.empty()){
			puts("NO");
			exit(0);
		}
		if(st.top().r==w[i]){
			st.clear();
			st.push(0,w[i]);
		}
		else{
			st.flip(w[i]);
			if(st.top().r!=w[i])st.push(w[i],w[i]);
		}
		// cerr<<"d["<<i+1<<"] in "<<st<<endl;
	}
	puts("YES");
	LL cur=st.top().r;
	R(i,n-2,1){
		d[i+1]=cur;
		// cerr<<"d["<<i+1<<"]="<<cur<<endl;
		st.revert();
		// cerr<<"st="<<st<<endl;
		// cerr<<"w["<<i<<"]="<<w[i]<<endl;
		assert(st.top().r<=w[i]);
		if(st.top().r==w[i]){
			cur=-sgn(cur)*w[i];
		}
		else if(abs(cur)==w[i]){
			cur=-sgn(cur)*st.top().r;
		}
		else cur=sgn(cur)*(w[i]-abs(cur));
	}
	d[1]=cur;
	a[0]=0;
	F(i,1,n-1)a[i]=a[i-1]+d[i];
	LL mn=*min_element(a,a+n);
	D(i,n)a[i]+=-mn;
	// reverse(a,a+n);
	D(i,n)printf("%lld ",a[i]);
	printf("\n");
	F(i,1,n-2)assert(max(max(a[i-1],a[i]),a[i+1])-min(min(a[i-1],a[i]),a[i+1])==w[i]);
	return 0;
}
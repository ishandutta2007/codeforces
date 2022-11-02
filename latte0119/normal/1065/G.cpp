#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

template<class T>
vector<int>zalgorithm(T s){
    vector<int>a(s.size());
    a[0]=s.size();
    int i=1,j=0;
    while(i<s.size()){
        while(i+j<s.size()&&s[j]==s[i+j])j++;
        a[i]=j;
        if(j==0){i++;continue;}
        int k=1;
        while(i+k<s.size()&&k+a[k]<j)a[i+k]=a[k],k++;
        i+=k;j-=k;
    }
    return a;
}

int N,K,M;


vint calcPre(const string &s,const string &p){
	string X=s+p;
	vint z=zalgorithm(X);
	vint a(p.size()+1);

	for(int i=1;i<=p.size();i++){
		if(z[X.size()-i]==i)a[i]=1;
	}
	return a;
}

vint calcSuf(const string &s,const string &p){
	string X=p+s;
	vint z=zalgorithm(X);
	vint a(p.size()+1);

	for(int i=1;i<=p.size();i++){
		if(z[X.size()-i]==i)a[i]=1;
	}
	return a;
}

int calcOcc(const string &s,const string &p){
	string X=p+s;
	vint z=zalgorithm(X);
	int ret=0;
	for(int i=0;i<s.size();i++)if(z[p.size()+i]>=p.size())ret++;
	return ret;
}

int mrg(const vint &a,const vint &b){
	int cnt=0;
	for(int i=0;i<a.size();i++)if(a[i]&&b[b.size()-1-i])cnt++;
	return cnt;
}

vector<int>pre[222],suf[222];
int occ[222];

vector<string>fi;
void calc(string s){
	int t;
	if(N<=1){
		t=0;
	}
	else{
		t=2;
		while(fi[t].size()<s.size())t++;
	}



	rep(k,2){
		pre[t+k]=calcPre(fi[t+k],s);
		suf[t+k]=calcSuf(fi[t+k],s);
		occ[t+k]=calcOcc(fi[t+k],s);
		chmin(occ[t+k],K+1);
	}

	
	int BC=mrg(suf[t],pre[t+1]);
	int BA=mrg(suf[t],pre[t]);
	for(int i=t+2;i<=N;i++){
		occ[i]=occ[i-1]+occ[i-2]+BC;
		chmin(occ[i],K+1);
		swap(pre[i],pre[i-2]);
		swap(suf[i],suf[i-2]);
		swap(BC,BA);
	}
}

signed main(){
	fi.pb("0");
	fi.pb("1");
	while(fi.back().size()<10000){
		fi.pb(fi[fi.size()-2]+fi[fi.size()-1]);		
	}

	cin>>N>>K>>M;
	K--;


	string ans;
	for(int i=0;i<M;i++){
		if(i){
			if(suf[N][ans.size()]){
				if(K==0)break;
				K--;
			}
		}

		calc(ans+"0");
		int tmp=occ[N];
		if(tmp<=K){
			K-=tmp;
			ans+="1";
			calc(ans);
		}
		else{
			ans+="0";
		}
	}
	cout<<ans<<endl;
	return 0;
}
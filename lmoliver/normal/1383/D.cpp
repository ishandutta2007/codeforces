#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=333;
int a[N][N];
int ans[N][N]={0};
int mr[N],mc[N];
typedef pair<int,int> P;
ostream &operator<<(ostream &o,P p){
	return o<<"("<<p.first<<","<<p.second<<")";
}
stack<P> s;
void test(P pos){
	if(pos.first>1&&pos.second>1&&ans[pos.first-1][pos.second-1]){
		if(!ans[pos.first-1][pos.second]){
			// cerr<<"push "<<P(pos.first-1,pos.second)<<endl;
			s.push(P(pos.first-1,pos.second));
		}
		if(!ans[pos.first][pos.second-1]){
			// cerr<<"push "<<P(pos.first,pos.second-1)<<endl;
			s.push(P(pos.first,pos.second-1));
		}
	}
}
void put(P pos,int v){
	// cerr<<"put "<<pos<<" "<<v<<endl;
	ans[pos.first][pos.second]=v;
	test(pos);
	pos.first++;
	pos.second++;
	if(ans[pos.first][pos.second]){
		test(pos);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			mr[i]=max(mr[i],a[i][j]);
			mc[j]=max(mc[j],a[i][j]);
		}
	}
	sort(mr+1,mr+n+1);
	reverse(mr+1,mr+n+1);
	sort(mc+1,mc+m+1);
	reverse(mc+1,mc+m+1);
	int ki=0,kj=0;
	for(int i=n*m;i>=1;i--){
		bool imr=mr[ki+1]==i,imc=mc[kj+1]==i;
		if(imr)ki++;
		if(imc)kj++;
		if(imr||imc){
			put(P(ki,kj),i);
		}
		else{
			assert(!s.empty());
			P p=s.top();
			s.pop();
			put(p,i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
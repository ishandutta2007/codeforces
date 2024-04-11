#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

const int N=1<<18;
pair<int, int> mast[2*N];
pair<int, int> mist[2*N];

pair<int, int> getmax(int a, int b){
	a+=N;
	b+=N;
	pair<int, int> v={-1, -1};
	while (a<=b){
		if (a%2) v=max(v, mast[a++]);
		if (!(b%2)) v=max(v, mast[b--]);
		a/=2;
		b/=2;
	}
	return v;
}

pair<int, int> getmin(int a, int b){
	a+=N;
	b+=N;
	pair<int, int> v={1e9, 1e9};
	while (a<=b){
		if (a%2) v=min(v, mist[a++]);
		if (!(b%2)) v=min(v, mist[b--]);
		a/=2;
		b/=2;
	}
	return v;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		mast[i+N]={a, i+1};
		mist[i+N]={a, i+1};
	}
	for (int i=N-1;i;i--){
		mast[i]=max(mast[i*2], mast[i*2+1]);
		mist[i]=min(mist[i*2], mist[i*2+1]);
	}
	for (int q=0;q<m;q++){
		int a,b,x;
		cin>>a>>b>>x;
		a--;
		b--;
		if (getmax(a, b).F!=x){
			cout<<getmax(a, b).S<<'\n';
		}
		else if(getmin(a, b).F!=x){
			cout<<getmin(a, b).S<<'\n';
		}
		else{
			cout<<"-1\n";
		}
	}
}
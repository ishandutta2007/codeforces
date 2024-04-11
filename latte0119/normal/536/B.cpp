#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

vector<int>zalgorithm(string s){
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

int N,M;
string P;

int acc[1111111];

signed main(){
	cin.tie();ios_base::sync_with_stdio(0);

	cin>>N>>M;
	cin>>P;
	vint Y(M);rep(i,M)cin>>Y[i],Y[i]--;
	vint z=zalgorithm(P);
	for(int i=0;i+1<M;i++){
		int d=Y[i+1]-Y[i];
		if(d>=P.size())continue;
		if(z[d]<P.size()-d){
			cout<<0<<endl;
			return 0;
		}
	}

	rep(i,M){
		acc[Y[i]]++;
		acc[Y[i]+P.size()]--;
	}
	int ans=1;
	rep(i,N){
		acc[i+1]+=acc[i];
		if(acc[i]==0)ans=ans*26%1000000007;
	}
	cout<<ans<<endl;
	return 0;
}
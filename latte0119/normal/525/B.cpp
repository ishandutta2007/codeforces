#include<vector>
#include<map>
#include<climits>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<bitset>
#include<cstring>
#include<list>
#include<ctime>
#include<iterator>
using namespace std;
typedef vector<string>vs;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<double>vd;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef vector<ll>vl;
#define rrep(i,x,n) for(int i=(x);i<(n);++i)
#define rep(i,x) rrep(i,0,(x))
#define fi first
#define se second
#define each(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define maxs(a,b) (a)=max(a,b)
#define mins(a,b) (a)=min(a,b)


int main(){
    string str;
    cin>>str;
    int M;cin>>M;
    vi cnt(str.size(),0);
    rep(i,M){
        int pos;cin>>pos;
        cnt[pos]++;
    }
    rep(i,str.size()/2)cnt[i+1]+=cnt[i];

    rep(i,str.size()/2){
        if(cnt[i+1]&1)swap(str[i],str[str.size()-i-1]);
    }
    cout<<str<<endl;
    return 0;
}
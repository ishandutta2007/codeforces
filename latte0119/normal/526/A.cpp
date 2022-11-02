#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#include<cmath>
#include<map>
#include<set>
#include<climits>
using namespace std;
typedef vector<string>vs;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<double>vd;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef vector<ll>vl;
typedef pair<int,pii>piii;
#define rrep(i,x,n) for(int i=(x);i<(n);++i)
#define rep(i,x) rrep(i,0,(x))
#define fi first
#define se second
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define maxs(a,b) (a)=max(a,b)
#define mins(a,b) (a)=min(a,b)
///#include<sstream>
///#include<cstring>
///#include<stack>
///#include<complex>


int main(){
    int N;
    string str;
    cin>>N>>str;


    for(int i=0;i<str.size();i++){
        if(str[i]=='.')continue;
        for(int h=1;i+h*4<str.size();h++){
            bool flag=true;
            for(int k=1;k<=4;k++)if(str[i+h*k]=='.')flag=false;
            if(flag){
                puts("yes");
                return 0;
            }
        }
    }

    puts("no");

    return 0;
}
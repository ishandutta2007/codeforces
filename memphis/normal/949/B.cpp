#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int inf=0x3f3f3f3f;
const int N=200005;

ll n;
int q;

int main(){
    cin>>n>>q;
    while(q--){
        ll x;
        scanf("%I64d",&x);
        while(x%2==0){
            x=n+(x/2);
        }
        printf("%I64d\n",x/2+1);
    }
}
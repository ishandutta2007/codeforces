/**
Finally I understand linear algebra more :P
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, mod = 1e9+7;

void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,int b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}

int n,m,a[maxn],basis[23];
int sz;
vector<pair<int,int>> q[maxn];
void ins(int x){
    for(int i = 20;i >= 0 ;i--){
        if( !(x & (1 << i)))continue;
        if(basis[i] == -1){
            return (void)(basis[i] = x,sz ++);
        }
        x ^= basis[i];
    }
}
bool is_in(int x){
    for(int i = 20 ;i>= 0; i--){
        if( x & (1<<i)){
            if(basis[i] == -1)return false;
            x ^= (basis[i]);
        }
    }
    return (x == 0);
}
int ans[maxn];

int main(){
    memset(basis,-1,sizeof(basis));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int l,x;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&l,&x);
        q[l].emplace_back(x,i);
    }
    int zero = 0;
    for(int i=1;i<=n;i++){
        if(a[i] > 0)
        ins(a[i]);
        else zero ++;
        for(auto j:q[i]){
            ans[j.second] = is_in(j.first) ? power(2,i  - sz) : 0;
        }
    }
    //cout << sz << endl;
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    /***

    */
}
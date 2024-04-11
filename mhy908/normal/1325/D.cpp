#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))
#define compress(x) x.erase(unique(all(x)), x.end())
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
const LL llinf=1987654321987654321;
const int inf=2000000000;
LL a, b;
int main(){
    scanf("%lld %lld", &a, &b);
    if(a>b||a%2!=b%2){
        puts("-1");
        return 0;
    }
    if(a==b){
        if(a==0)puts("0");
        else printf("1\n%lld", a);
        return 0;
    }
    LL c=a, d=(b-a)/2;
    if((c&d)==0)printf("2\n%lld %lld", c+d, d);
    else printf("3\n%lld %lld %lld", c, d, d);
}
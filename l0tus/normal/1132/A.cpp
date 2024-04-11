#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
using namespace std;
const int MN = 1e6+5;
const int INF = 1e9;

int A[MN],B[MN],N,M,K,cnt,tmp,ans,val;
string S;
int main()
{
    int a,b,c,d;
    bool ispos = false;
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> a >> b >> c >> d;
    if(c==0){
        if(a==d) ispos = true;
    }
    else{
        if(a==d && a>0) ispos = true;
    }
    cout << ispos;
}
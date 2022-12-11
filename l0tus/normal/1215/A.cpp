#include <bits/stdc++.h>
using namespace std;
#define first va
#define second vb
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int N,a1,a2,k1,k2,A[MN],B[MN],cnt,ans;
int c1,c2,m,M;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> a1 >> a2 >> k1 >> k2 >> N;
    if(k1<k2){
        cnt = a1;
        a1 = a2;
        a2 = cnt;
        cnt = k1;
        k1 = k2;
        k2 = cnt;
    }
    m = max(0,N-a1*(k1-1)-a2*(k2-1));
    while(N>0){
        if(a2){
            N -= k2;
            a2 --;
        }
        else{
            N -= k1;
            a1 --;
        }
        if(N<0) break;
        M++;
    }
    cout << m << ' ' << M;
}
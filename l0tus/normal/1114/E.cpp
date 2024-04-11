#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+10;
int N,cnt,B[100],val,res,ans,x;
bool ch[MN];
vector<int> A;
int gcd(int a, int b)
{
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(a%b,b);
}

mt19937 seed((unsigned)chrono::steady_clock::now().time_since_epoch().count());
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    int s = 1, e = 1e9, m;
    while(s<e){
        m = (s+e)/2;
        cout << "> " << m << '\n';
        cout.flush();
        cin >> val;
        if(val) s = m +1;
        else e = m;
    }
    uniform_int_distribution<int> ran(1, N);
    for(int i=1; i<=min(30,N); i++){
        while(1){
           x = ran(seed);
           if(!ch[x]) break;
        }
        ch[x] = 1;
        cout << "? " << x << '\n';
        cout.flush();
        cin >> val;
        A.push_back(val);
    }
    sort(A.begin(),A.end());
    if(A[A.size()-1]!=s) A.push_back(s);
    for(int i=0; i<A.size()-1; i++){
        B[i] = A[i+1] - A[i];
    }
    res = B[0];
    for(int i=1; i<A.size()-1; i++){
        res = gcd(res,B[i]);
    }
    cout << "! " << s-(N-1)*res << ' ' << res;
}
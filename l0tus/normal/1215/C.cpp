#include <bits/stdc++.h>
using namespace std;
#define first va
#define second vb
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int N,A[MN],B[MN],cnt,ans;
string S,T;
vector<int> s,t;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> N >> S >> T;
    for(int i=0; i<N; i++){
        cnt += (S[i]=='a')+(T[i]=='a');
        if(S[i]=='a' && T[i]=='b') s.push_back(i+1);
        if(S[i]=='b' && T[i]=='a') t.push_back(i+1);
    }
    if(cnt%2!=0){
        cout << -1;
        return 0;
    }
    int c = s.size()%2, d = t.size()%2;
    ans = s.size()/2+t.size()/2;
    if(c+d>0) ans += 2;
    cout << ans << '\n';
    for(int i=0; i<s.size(); i+=2){
        if(i+1<s.size()){
            cout << s[i] << ' ' << s[i+1] << '\n';
        }
    }
    for(int i=0; i<t.size(); i+=2){
        if(i+1<t.size()){
            cout << t[i] << ' ' << t[i+1] << '\n';
        }
    }
    if(c+d==2){
        c = s[s.size()-1];
        d = t[t.size()-1];
        cout << c << ' ' << c << '\n';
        cout << c << ' ' << d << '\n';
    }
}
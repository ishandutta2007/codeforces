#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

string s, t;
int n;
char ch[3];

void printLarge(char a, char b, char c) {
    a = ch[a];
    b = ch[b];
    c = ch[c];
    REP(i,0,n) cout<<a;
    REP(i,0,n) cout<<b;
    REP(i,0,n) cout<<c;
    cout<<endl;
}
void printRep  (char a, char b, char c) {
    a = ch[a];
    b = ch[b];
    c = ch[c];
    REP(i,0,n) cout<<a<<b<<c;
    cout<<endl;
}
void setCh     () {
    int dif=0;
    string l=s+t;
    bitset<3> found; found.reset();
    REP(i,0,4) {
        if(!found[l[i]-'a']) {
            found[l[i]-'a']=1;
            ch[dif++] = l[i];
        }
    }
    REP(i,0,3)
        if(!found[i])
            ch[dif++] = 'a'+i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cin>>s>>t;
    cout<<"YES"<<endl;
    if(s[0] == s[1] || t[0] == t[1]) {
        if(t[0] == t[1]) swap(s,t);
        setCh();
        if(t[1] == s[0]) printRep(0, 1, 2);
        else printRep(0, 2, 1);
    } else {
        setCh();
        if(s[0] == t[0]) {
            printLarge(2, 1, 0);
        } else if(s[0] == t[1] && s[1] == t[0]) {
            printLarge(0, 2, 1);
        } else if(s[0] != t[1] && s[1] == t[0]) {
            printLarge(0, 2, 1);
        } else if(s[0] == t[1] && s[1] != t[0]) {
            printLarge(0, 2, 1);
        } else {
            printLarge(1, 0, 2);
        }
    }
}
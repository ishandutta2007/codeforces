#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

string s, s1, s2;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    getline(cin,s);
    getline(cin,s1);
    getline(cin,s2);
    //s1 += s2;
    bool f1 = 0, f2 = 0;
    
    int uk = s.find(s1);
    f1 =(uk!=-1 && (int)s.find(s2,uk+sz(s1))!=-1);
    
    reverse(all(s));//s.reverse();
    uk = s.find(s1);
    f2 =(uk!=-1 && (int)s.find(s2,uk+sz(s1))!=-1);
    
    if (f1 && !f2) cout << "forward\n";
    if (!f1 && f2) cout << "backward\n";
    if (f1 && f2) cout << "both\n";
    if (!f1 && !f2) cout << "fantasy\n";
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define INF 1e9

const int MX=1e5;
string s1, s2;
int n;
vi aToB;
vi bToA;

int main() {
    cin>>n>>s1>>s2;
    REP(i,0,n) {
        if(s1[i]=='a' && s2[i]=='b')
            aToB.push_back(i+1);
        if(s1[i]=='b' && s2[i]=='a')
            bToA.push_back(i+1);
    }
    if((aToB.size()+bToA.size())%2 == 1) {
        cout<<-1<<endl;
        return 0;
    }
    if(aToB.size()%2 == 0) {
        cout<<aToB.size()/2+bToA.size()/2<<endl;
        REP(i,0,aToB.size()/2) {
            int j=i+aToB.size()/2;
            cout<<aToB[i]<<" "<<aToB[j]<<endl;
        }
        REP(i,0,bToA.size()/2) {
            int j=i+bToA.size()/2;
            cout<<bToA[i]<<" "<<bToA[j]<<endl;
        }
    } else {
        cout<<(aToB.size()+bToA.size())/2+1<<endl;
        REP(i,0,aToB.size()/2) {
            int j=i+aToB.size()/2;
            cout<<aToB[i]<<" "<<aToB[j]<<endl;
        }
        REP(i,0,bToA.size()/2) {
            int j=i+bToA.size()/2;
            cout<<bToA[i]<<" "<<bToA[j]<<endl;
        }
        cout<<aToB.back()<<" "<<aToB.back()<<endl;
        cout<<aToB.back()<<" "<<bToA.back()<<endl;
    }
}
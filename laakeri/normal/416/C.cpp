#include <iostream>
#include <algorithm>
#include <map>
#define F first
#define S second

using namespace std;

struct cu{
    int s;
    int m;
    int id;
};

int comp (cu c1,cu c2){
    return c1.m<c2.m;
}

vector<cu > cs;
vector<pair<int,int> > ts;
int used[1001];

map<int,int> v;

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        cu c;
        c.s=a;
        c.m=b;
        c.id=i+1;
        cs.push_back(c);
    }
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int a;
        cin>>a;
        ts.push_back(make_pair(a,i+1));
    }
    sort (cs.rbegin(),cs.rend(),comp);
    sort (ts.begin(),ts.end());
    int r=0;
    int f=0;
    for (auto c:cs){
        for (int i=0;i<t;i++){
            if (ts[i].F>=c.s&&(!used[i])){
                r+=c.m;
                f++;
                used[i]=1;
                v[c.id]=ts[i].S;
                break;
            }
        }
    }
    cout <<f<<" "<<r<<endl;
    for (auto vt:v){
        cout <<vt.F<<" "<<vt.S<<endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct e{
    int a,b,w;
    bool operator< (const e&e2) const{
        return e2.w>w;
    }
};

int mt[400000];
int mtn[400000];
vector<e> es;
set<int> lol;

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e ee;
        ee.a=a;
        ee.b=b;
        ee.w=c;
        es.push_back(ee);
    }
    sort(es.begin(), es.end());
    int mv=0;
    int ed=0;
    for (auto ee:es){
        if (ee.w>ed){
            //cout<<"asdf"<<endl;
            for (int asd:lol){
                //cout<<asd<<endl;
                mt[asd]=max(mtn[asd], mt[asd]);
                mtn[asd]=0;
            }
            ed=ee.w;
            lol.clear();
        }
        //cout<<"w "<<ee.w<<endl;
        //cout<<"b "<<ee.b<<endl;
        mtn[ee.b]=max(mtn[ee.b], mt[ee.a]+1);
        mv=max(mv, mtn[ee.b]);
        lol.insert(ee.b);
    }
    cout<<mv<<endl;
}
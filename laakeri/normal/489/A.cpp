#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second

using namespace std;

pair<int, int> a[3001];
int p[3001];

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a[i].F;
        a[i].S=i;
    }
    sort(a, a+n);
    vector<pair<int, int> > v;
    for (int i=0;i<n;i++){
        p[a[i].S]=i;
    }
    for (int i=0;i<n;i++){
        for (int ii=0;ii<n;ii++){
            if (p[ii]==i){
                v.push_back({i, ii});
                swap(p[i], p[ii]);
            }
        }
    }
    cout<<v.size()<<endl;
    for (int i=0;i<v.size();i++){
        cout<<v[i].F<<" "<<v[i].S<<'\n';
    }
}
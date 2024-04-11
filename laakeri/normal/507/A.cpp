#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int, int> > asd(n);
    for (int i=0;i<n;i++){
        cin>>asd[i].F;
        asd[i].S=i+1;
    }
    sort(asd.begin(), asd.end());
    vector<int> v;
    for (auto lol:asd){
        if (lol.F<=k){
            k-=lol.F;
            v.push_back(lol.S);
        }
    }
    cout<<v.size()<<endl;
    for (int a:v){
        cout<<a<<" ";
    }
}
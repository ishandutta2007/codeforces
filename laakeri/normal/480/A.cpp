#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int, int> > lol(n);
    for (int i=0;i<n;i++){
        cin>>lol[i].F>>lol[i].S;
    }
    sort(lol.begin(), lol.end());
    int d=0;
    for (auto a:lol){
        if (a.S>=d){
            d=a.S;
        }
        else{
            d=a.F;
        }
    }
    cout<<d<<endl;
}
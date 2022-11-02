#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second

using namespace std;

int main(){
    vector<pair<int, int> > lol;
    int v=-1;
    int v1=0;
    int v2=0;
    int t1;
    cin>>t1;
    for (int i=0;i<t1;i++){
        int a;
        cin>>a;
        lol.push_back({a, 1});
    }
    int t2;
    cin>>t2;
    for (int i=0;i<t2;i++){
        int a;
        cin>>a;
        lol.push_back({a, 2});
    }
    sort(lol.begin(), lol.end());
    v=3*t1-3*t2;
    v1=t1*3;
    v2=t2*3;
    int t1p=0;
    int t2p=0;
    for (int i=0;i<lol.size();i++){
        if (lol[i].S==1){
            t1--;
            t1p+=2;
        }
        else{
            t2--;
            t2p+=2;
        }
        if (i<lol.size()-1&&lol[i].F==lol[i+1].F){

        }
        else{
            if (3*t1-3*t2+t1p-t2p>v){
                v=3*t1-3*t2+t1p-t2p;
                v1=3*t1+t1p;
                v2=3*t2+t2p;
            }
        }
    }
    cout<<v1<<":"<<v2<<endl;
}
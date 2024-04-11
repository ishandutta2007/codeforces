#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> lol(n);
    for (int i=0;i<n;i++){
        cin>>lol[i];
    }
    int m;
    cin>>m;
    vector<int> lol2(m);
    for (int i=0;i<m;i++){
        cin>>lol2[i];
    }
    sort(lol.begin(), lol.end());
    sort(lol2.begin(), lol2.end());
    int v=0;
    if (n<m){
        for (int i=0;i<n;i++){
            for (int ii=0;ii<m;ii++){
                if (lol[i]-lol2[ii]<2&&lol[i]-lol2[ii]>-2){
                    v++;
                    lol2[ii]=-999;
                    break;
                }
            }
        }
    }
    else {
        for (int i=0;i<m;i++){
            for (int ii=0;ii<n;ii++){
                if (lol[ii]-lol2[i]<2&&lol[ii]-lol2[i]>-2){
                    v++;
                    lol[ii]=-999;
                    break;
                }
            }
        }
    }
    cout<<v<<endl;
}
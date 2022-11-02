#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pc;
vector<int> c;

int main(){
    int n,m;
    cin>>n>>m;
    int i;
    for (i=0;i<n;i++){
        int a;
        cin>>a;
        pc.push_back(a);
    }
    for (i=0;i<m;i++){
        int a;
        cin>>a;
        c.push_back(a);
    }
    sort(pc.begin(),pc.end());
    sort(c.begin(),c.end());
    int ci=0;
    int f=0;
    for (int p:pc){
        while (ci<m){
            if (c[ci]>=p){
                f++;
                ci++;
                break;
            }
            ci++;
        }
        if (ci==m) {
            break;
        }
    }
    cout<<n-f<<endl;
}
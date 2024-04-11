#include <iostream>
#include <algorithm>

using namespace std;

vector<int> acq;

int q[101];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>q[i+1];
    }
    for (int i=0;i<m;i++){
        int a;
        cin>>a;
        acq.push_back(q[a]);
        q[a]=0;
    }
    long long p=0;
    for (int i=1;i<=n;i++){
        p+=q[i];
    }
    sort (acq.rbegin(),acq.rend());
    for (int ac:acq){
        p+=max(p,(long long)ac);
    }
    cout <<p<<endl;
}
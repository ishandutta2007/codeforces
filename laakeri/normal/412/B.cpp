#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> asd;

int main(){
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        asd.push_back(a);
    }
    sort (asd.begin(),asd.end());
    cout <<asd[asd.size()-k]<<endl;
}
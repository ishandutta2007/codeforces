#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second

typedef long long ll;

using namespace std;

int main(){
    int n,x;
    int s=0;
    cin>>n>>x;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        s+=a;
    }
    if (s<0){
        s=-s;
    }
    int v=s/x;
    if (s%x>0){
        v++;
    }
    cout <<v<<endl;
}
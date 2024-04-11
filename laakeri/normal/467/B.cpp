#include <iostream>

using namespace std;

int p[1011];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<m+1;i++){
        cin>>p[i];
    }
    int f=p[m];
    int v=0;
    for (int i=0;i<m;i++){
        int d=0;
        for (int ii=0;ii<n;ii++){
            if (((1<<ii)&p[i])!=((1<<ii)&f)){
                d++;
            }
        }
        if (d<=k) v++;
    }
    cout<<v<<endl;
}
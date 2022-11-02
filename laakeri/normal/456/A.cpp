#include <iostream>

using namespace std;

int mq[100001];

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        mq[a]=max(mq[a],b);
    }
    int q=0;
    for (int i=1;i<=n;i++){
        if (mq[i]){
            if (mq[i]<q){
                cout<<"Happy Alex"<<endl;
                return 0;
            }
            else{
                q=mq[i];
            }
        }
    }
    cout<<"Poor Alex"<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int N;
int A[100][100];
int main(){
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>A[i][j];

    vector<int>ans;
    for(int i=0;i<N;i++){
        bool flag=true;
        for(int j=0;j<N;j++){
            if(i==j)continue;
            if(A[i][j]==1||A[i][j]==3)flag=false;
        }
        if(flag)ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        if(i)cout<<" ";
        cout<<ans[i]+1;
    }
    cout<<endl;
    return 0;
}
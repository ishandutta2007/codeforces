#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    int u,v,mini=0,cur=0;
    for(int i=0;i<N;i++){
        cin>>u>>v;
        cur-=u;
        cur+=v;
        mini=max(cur,mini);
    }
    cout<<mini<<"\n";
	return 0;
}
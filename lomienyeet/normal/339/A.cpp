#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int temp,arr[100],cnt=0;
    while(cin>>temp){
        arr[cnt++]=temp;
    }
    sort(arr,arr+cnt);
    for(int i=0;i<cnt-1;i++)cout<<arr[i]<<"+";
    cout<<arr[cnt-1]<<"\n";
    return 0;
}
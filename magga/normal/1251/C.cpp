#include<bits/stdc++.h>
using namespace std;
int value(char c){
    return int(c)-int('0');
}
void solve(){
    string s;cin>>s;
    queue<int>odd;
    queue<int>even;
    long long int k =s.size();
    int arr[k];
    for(long long int i=0;i<k;i++){
        int p = value(s[i]);
        if(p%2==0){
            even.push(p);
        }else{
            odd.push(p);
        }
    }
    long long int j=0;
    for(long long int i=0;i<k;i++){
        if(odd.size()==0){
            arr[j]=even.front();
            even.pop();
            j++;
        }
        else if(even.size()==0){
            arr[j]=odd.front();
            odd.pop();
            j++;
        }
        else if(even.front()<odd.front()){
            arr[j]=even.front();
            even.pop();
            j++;
        }else{
            arr[j]=odd.front();
            odd.pop();
            j++;
        }
    }
    for(long long int i=0;i<k;i++){
        cout<<arr[i];
    }
    cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
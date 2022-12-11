/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    string first[n];
    string last[n];
    for(int i=0;i<n;i++){
        cin>>first[i]>>last[i];
        if(first[i]>last[i]){
            swap(first[i],last[i]);
        }
    }
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]--;
    }
    string handles[n];
    for(int ord=0;ord<n;ord++){
        int i=arr[ord];
        if(ord==0||handles[ord-1]<first[i]){
            handles[ord]=first[i];
        }
        else{
            if(handles[ord-1]<last[i]){
                handles[ord]=last[i];
            }
            else{
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    //acbed
    //cbade
 
    return 0;
}
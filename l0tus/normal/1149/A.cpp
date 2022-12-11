#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int N,A,B,C,S,val,sum,cnt,ans;
bool ch1,ch2;

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> val;
        sum += val;
        if(val==1) A++;
        if(val==2) B++;
    }
    if(A&&B){
        cout << "2 1 ";
        for(int i=0; i<B-1; i++) cout << "2 ";
        for(int i=0; i<A-1; i++) cout << "1 ";
    }
    else{
        if(B) for(int i=0; i<N; i++) cout << "2 ";
        else for(int i=0; i<N; i++) cout << "1 ";
    }
}
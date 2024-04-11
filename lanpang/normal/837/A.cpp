#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int len = 0;
    int ans = 0;
    char ch;
    getchar();
    for(int i = 0; i < n; i++){
        scanf("%c",&ch);
        //cout << ch << endl;
        if(ch == ' ') {
            ans = max(ans, len);
            len = 0;
        }
        else{
            if(ch >= 'A' && ch <= 'Z') len++;
        }
    }
    ans = max(ans, len);
    cout << ans;
}
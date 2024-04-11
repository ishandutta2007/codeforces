#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int has[500];
int mi[500];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n-1;i++){
        has[s[i*2]]++;
        if (s[i*2+1]>='A'&&s[i*2+1]<='Z'){
            s[i*2+1]=s[i*2+1]-'A'+'a';
        }
        else{
            s[i*2+1]=s[i*2+1]-'a'+'A';
        }
        has[s[i*2+1]]--;
        mi[s[i*2+1]]=min(mi[s[i*2+1]], has[s[i*2+1]]);
    }
    int v=0;
    for (int i=0;i<500;i++){
        v-=mi[i];
    }
    cout<<v<<endl;
}
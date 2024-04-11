#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int h[300];
int ok[300001];

int main(){
    string a,b;
    cin>>a>>b;
    for (int i=0;i<b.size();i++){
        h[b[i]]++;
    }
    int v1=0;
    int v2=0;
    for (int i=0;i<a.size();i++){
        if (h[a[i]]>0){
            v1++;
            h[a[i]]--;
            ok[i]=1;
        }
    }
    for (int i=0;i<a.size();i++){
        if (ok[i]==0){
            if (a[i]>='a'&&a[i]<='z'){
                if (h[a[i]+'A'-'a']>0){
                    h[a[i]+'A'-'a']--;
                    v2++;
                }
            }
            else{
                if (h[a[i]+'a'-'A']>0){
                    h[a[i]+'a'-'A']--;
                    v2++;
                }
            }
        }
    }
    cout<<v1<<" "<<v2<<endl;
}
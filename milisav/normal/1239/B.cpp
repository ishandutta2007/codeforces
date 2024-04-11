#include<bits/stdc++.h>
using namespace std;
char s[800000];
int n;
int p[800000];
int t[800000];
vector<pair<int,pair<int,int> > > ans;
int main() {
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++) {
        if(s[i]=='(') p[i+1]=p[i]+1;
        else p[i+1]=p[i]-1;
    }
    for(int i=0;i<n;i++) p[i]=p[i+1];
    if(p[n-1]!=0) {
        printf("0\n");
        printf("1 1\n");
        return 0;
    }
    int mn=p[0];
    int ct=1;
    for(int i=1;i<n;i++) {
        if(p[i]<mn) {
            mn=p[i];
            ct=0;
        }
        if(p[i]==mn) ct++;
    }
    ans.push_back({ct,{0,0}});


    int u=-1;
    for(int i=0;i<n;i++) {
        if(s[i]==')') u=i;
        if(p[i]==mn) break;
    }
    int v=n+1;
    if(p[n-1]!=mn) {
        for(int i=n-1;i>=1;i--) {
            if(s[i]=='(') v=i;
            if(p[i-1]==mn) break;
        }
    }
    if(u!=-1 && v!=n+1) {
        for(int i=0;i<n;i++) {
            t[i]=p[i];
            if(i>=u && i<v) t[i]=p[i]+2;
        }
        int cm=t[0];
        int ot=1;
        for(int i=1;i<n;i++) {
            if(t[i]<cm) {
                cm=t[i];
                ot=0;
            }
            if(t[i]==cm) ot++;
        }
        ans.push_back({ot,{u,v}});
    }

    u=-1;
    for(int i=0;i<n;i++) {
        if(s[i]==')') u=i;
        if(p[i]==mn || p[i]==mn+1) break;
    }
    v=n+1;
    if(p[n-1]!=mn && p[n-1]!=mn+1) {
        for(int i=n-1;i>=1;i--) {
            if(s[i]=='(') v=i;
            if(p[i-1]==mn || p[i-1]==mn+1) break;
        }
    }
    if(u!=-1 && v!=n+1) {
        //cout<<u<<" "<<v<<endl;
        for(int i=0;i<n;i++) {
            t[i]=p[i];
            if(i>=u && i<v) t[i]=p[i]+2;
        }
        int cm=t[0];
        int ot=1;
        for(int i=1;i<n;i++) {
            if(t[i]<cm) {
                cm=t[i];
                ot=0;
            }
            if(t[i]==cm) ot++;
        }
        ans.push_back({ot,{u,v}});
    }

    u=-1;
    int ot=0;
    for(int i=0;i<n;i++) {

        if(s[i]==')' && u!=-1) {
            ans.push_back({ct+ot,{u,i}});
        }
        if(p[i]==mn || p[i]==mn+1) {
            u=-1;
            ot=0;
        }
        else {
            if(u==-1 && s[i]=='(') {
                u=i;
                ot=0;
            }
        }
        if(p[i]==mn+2) ot++;
    }

    u=-1;
    ot=0;
    for(int i=0;i<n;i++) {

        if(s[i]==')' && u!=-1) {
            ans.push_back({ot,{u,i}});
        }
        if(p[i]==mn) {
            u=-1;
            ot=0;
        }
        else {
            if(u==-1 && s[i]=='(') {
                u=i;
                ot=0;
            }
        }
        if(p[i]==mn+1) ot++;
    }

    sort(ans.begin(),ans.end());
    printf("%d\n",ans.back().first);
    printf("%d %d\n",ans.back().second.first+1,ans.back().second.second+1);
    return 0;
}
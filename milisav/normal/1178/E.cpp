#include<bits/stdc++.h>
using namespace std;
int n;
char s[2000000];
int c[10];
int d[10];
pair<char,int> mid;
vector<pair<char,int> > lv;
vector<pair<char,int> > rv;
int mv() {
    int k=0;
    if(c[1]>c[k]) k=1;
    if(c[2]>c[k]) k=2;
    return k;
}
int main() {
    scanf("%s",s);
    n=strlen(s);
    int t=n/2;
    for(int i=0;i<n;i++){
        c[s[i]-'a']++;
    }
    int k=0;
    int m;
    if(c[1]>c[k]) k=1;
    if(c[2]>c[k]) k=2;
    if(c[k]%2==0) {
        int l,r;
        int ct=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='a'+k) ct++;
            if(ct==c[k]/2) {
                l=i;
                break;
            }
        }
        ct=0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='a'+k) ct++;
            if(ct==c[k]/2) {
                r=i;
                break;
            }
        }
        m=c[k]/2;
        c[0]=c[1]=c[2]=0;
        for(int i=l+1;i<r;i++) {
            c[s[i]-'a']++;
        }
        mid={'a'+mv(),c[mv()]};
        while(l>=0 && r<=n-1) {
            lv.push_back({'a'+k,1});
            rv.push_back({'a'+k,1});
            l--;
            c[0]=c[1]=c[2]=d[0]=d[1]=d[2]=0;
            while(l>=0 && s[l]!='a'+k) {
                c[s[l]-'a']++;
                l--;
            }
            r++;
            while(r<=n-1 && s[r]!='a'+k) {
                d[s[r]-'a']++;
                r++;
            }
            c[0]=min(c[0],d[0]);
            c[1]=min(c[1],d[1]);
            c[2]=min(c[2],d[2]);
            lv.push_back({'a'+mv(),c[mv()]});
            rv.push_back({'a'+mv(),c[mv()]});
        }
        for(int i=lv.size()-1;i>=0;i--) {
            for(int j=0;j<lv[i].second;j++) printf("%c",lv[i].first);
        }
        for(int j=0;j<mid.second;j++) printf("%c",mid.first);
        for(int i=0;i<rv.size();i++) {
            for(int j=0;j<lv[i].second;j++) printf("%c",lv[i].first);
        }
    }
    else {
        int l,r;
        int ct=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='a'+k) ct++;
            if(ct==c[k]/2+1) {
                l=i;
                break;
            }
        }
        ct=0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='a'+k) ct++;
            if(ct==c[k]/2+1) {
                r=i;
                break;
            }
        }
        m=c[k]/2;
        while(l>=0 && r<=n-1) {
            lv.push_back({'a'+k,1});
            rv.push_back({'a'+k,1});
            //cout<<l<<"  "<<r<<endl;
            l--;
            c[0]=c[1]=c[2]=d[0]=d[1]=d[2]=0;
            while(l>=0 && s[l]!='a'+k) {
                c[s[l]-'a']++;
                l--;
            }
            r++;
            while(r<=n-1 && s[r]!='a'+k) {
                d[s[r]-'a']++;
                r++;
            }
            //cout<<c[0]<<" "<<d[0]<<endl;
            //cout<<c[1]<<" "<<d[1]<<endl;
            //cout<<c[2]<<" "<<d[2]<<endl;
            c[0]=min(c[0],d[0]);
            c[1]=min(c[1],d[1]);
            c[2]=min(c[2],d[2]);
            lv.push_back({'a'+mv(),c[mv()]});
            rv.push_back({'a'+mv(),c[mv()]});
        }
        for(int i=lv.size()-1;i>=0;i--) {
            for(int j=0;j<lv[i].second;j++) printf("%c",lv[i].first);
        }
        for(int i=1;i<rv.size();i++) {
            for(int j=0;j<lv[i].second;j++) printf("%c",lv[i].first);
        }
    }
}
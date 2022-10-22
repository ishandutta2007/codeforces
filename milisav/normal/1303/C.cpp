#include<bits/stdc++.h>
using namespace std;
int t;
char s[50000];
deque<char> dq;
bool ap[226];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%s",s);
        int n=strlen(s);
        for(int i=0;i<26;i++) ap['a'+i]=false;
        while(!dq.empty()) dq.pop_front();
        dq.push_back(s[0]);
        int j=0;
        bool pos=true;
        ap[s[0]]=true;
        for(int i=1;i<n && pos;i++) {
            if(j+1==dq.size() && j==0) {
                if(ap[s[i]]) pos=false;
                dq.push_back(s[i]);
                ap[s[i]]=true;
                j++;
            }
            else {
                if(j+1==dq.size()) {
                    if(dq[j-1]==s[i]) j--;
                    else {
                        if(ap[s[i]]) pos=false;
                        dq.push_back(s[i]);
                        ap[s[i]]=true;
                        j++;
                    }
                }
                else {
                    if(j==0) {
                        if(dq[j+1]==s[i]) j++;
                        else {
                            if(ap[s[i]]) pos=false;
                            dq.push_front(s[i]);
                            ap[s[i]]=true;
                        }
                    }
                    else {
                        if(dq[j+1]==s[i]) j++;
                        else {
                            if(dq[j-1]==s[i]) j--;
                            else pos=false;
                        }
                    }
                }
            }
        }
        if(!pos) printf("NO\n");
        else {
            printf("YES\n");
            for(int i=0;i<26;i++) {
                if(!ap['a'+i]) dq.push_back('a'+i);
            }
            for(int i=0;i<dq.size();i++) printf("%c",dq[i]);
            printf("\n");
        }
    }
    return 0;
}
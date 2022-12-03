#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,f,s;
    int a[100010],b[100010];
    char ch;
    n=0;
    ch=getchar();
    while((ch=='_')||(ch=='#')) {
        if (ch=='_') {
            a[n++]=0;
        }
        else {
            a[n++]=1;
        }
        ch=getchar();
    }

    for(i=0;i<n;i++) {
        if (a[i]!=0) break;
    }
    if (i==n) {
        cout<<0<<endl;
        return 0;
    }
    
    i=0;
    k=n;
    l=1;
    while((i<n)&&(a[i]==0)){
        i++;
        l++;
    }
    if (l!=1) k=l-1;

    while(i<n) {
        while((i<n)&&(a[i]==1)){
            i++;
        }
        l=0;
        while((i<n)&&(a[i]==0)){
            i++;
            l++;
        }
        if (i==n) l++;
        if (l-1<k) k=l-1;
    }

    if (k==0) {
        f=1;
        i=0;
        while((i<n)&&(a[i]==0)){
            i++;
            l++;
        }
        if (l!=1) f=0;
        if (f==1) while(i<n) {
            while((i<n)&&(a[i]==1)){
                i++;
            }
            l=0;
            
            while((i<n)&&(a[i]==0)){
                i++;
                l++;
            }
            if (i==n) l++;
            if (l!=1) {
                f=0;
                break;
            }
        }

        if (f==0) {
            cout<<-1;
            return 0;
        }
        else {
            s=0;
            i=0;
            while(i<n) {
                k=0;
                while((i<n)&&(a[i]==1)){
                    i++;
                    k++;
                }
                if (k!=0) {
                    b[s++]=k;
                }
                while((i<n)&&(a[i]==0)) {
                    i++;
                }
            }
            cout<<s<<endl;
            for(i=0;i<s;i++) cout<<b[i]<<' ';
        }
    }
    else if (k==1){
        f=1;
        i=0;
        while((i<n)&&(a[i]==0)){
            i++;
            l++;
        }
        if (l%2==0) f=0;
        if (f==1) while(i<n) {
            while((i<n)&&(a[i]==1)){
                i++;
            }
            l=0;
            while((i<n)&&(a[i]==0)){
                i++;
                l++;
            }
            if (i==n) l++;
            if (l%2==1) {
                f=0;
                break;
            }
        }

        if (f==0) {
            cout<<-1;
            return 0;
        }
        else {
            s=0;
            i=1;
            while(i<n) 
            {
                k=0;
                while((i<n)&&(a[i]==1)){
                    i++;
                    k++;
                }
                if (k!=0) {
                    b[s++]=k+1;
                }
                i+=2;
                while((i<n)&&(a[i]==0)) {
                    i+=2;
                    b[s++]=1;
                }
            }
            cout<<s<<endl;
            for(i=0;i<s;i++) cout<<b[i]<<' ';
        }
    }
    else {
        if (k>=4) k=2;
        f=1;
        i=0;
        while((i<n)&&(a[i]==0)){
            i++;
            l++;
        }
        if (l-k==1) f=0;
        if (f==1) while(i<n) {
            int p=0;
            while((i<n)&&(a[i]==1)){
                i++;
            }
            l=0;
            
            while((i<n)&&(a[i]==0)){
                i++;
                l++;
            }
            if (i==n) l++;
            if (l-k==2) {
                f=0;
                break;
            }
        }

        if (f==0) {
            cout<<-1;
            return 0;
        }
        else {
            s=0;
            i=0;
            while(i<n) {
                int p=0;
                while((i<n)&&(a[i]==1)){
                    i++;
                    p++;
                }
                if (p!=0) {
                    b[s++]=p+k;
                }
                if (i!=0) l=0;
                else l=1;
                while((i<n)&&(a[i]==0)){
                    l++;
                    i++;
                }
                if (i!=n) l--;
                if ((l-k)%2==1) {
                    b[s++]=2;
                    for(j=0;j<l-k-3;j+=2) {
                        b[s++]=1;
                    }
                }
                else {
                    for(j=0;j<l-k;j+=2) {
                        b[s++]=1;
                    }
                }
            }
            cout<<s<<endl;
            for(i=0;i<s;i++) cout<<b[i]<<' ';
        }
    }

    return 0;
}
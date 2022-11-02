#include<bits/stdc++.h>
using namespace std;
const int chtholly = 0;
const int N = 30;
bool v[N][N];
int n;
using pii = pair<int,int>;

void construct(int n, int tar, int par, int val)
{
    int j,k,l;
    bool pass = false;
    pii tar_1,tar_2;
    cout<<par<<" ";
    if(n==1)
    {
        return;
    }
    else if(n<=N)
    {
        for(j=1; j<n; j++)
        {
            if(j%2==1)
            {
                for(k=0; k<N; k++)
                    for(l=0; l<N; l++)
                        if(v[j][k] && v[n-j-1][l])
                        {
                            if(j>2*(n-j-1) || (n-j-1) > 2*j)
                            {
                                if(k+l+1 == tar)
                                {
                                    tar_1 = {j,k};
                                    tar_2 = {n-j-1,l};
                                    pass = true;
                                }
                            }
                            else if(k+l == tar)
                            {
                                tar_1 = {j,k};
                                tar_2 = {n-j-1,l};
                                pass = true;
                            }
                        }
            }
        }
        construct(tar_1.first,tar_1.second,val,val+1);
        construct(tar_2.first,tar_2.second,val,val+tar_1.first+1);
    }
    else
    {
        if(tar>2)
        {
            construct(n-2,tar-1,val,val+1);
            construct(1,0,val,n+val-1);
        }
        else if(tar==2)
        {
            int cur = 2;
            while(cur*2<n)
                cur*=2;
            if(cur+1 == n)
            {
                construct(n-4,1,val,val+1);
                construct(3,0,val,val+n-3);
            }
            else
            {
                construct(n-2,1,val,val+1);
                construct(1,0,val,val+n-1);
            }
        }
        else if(tar==0)
        {
            construct(n/2,0,val,val+1);
            construct(n/2,0,val,val+1+n/2);
        }
        else
        {
            int cur = 2;
            while(cur*2<n)
                cur*=2;
            if(cur+cur/2 == n+1)
            {
                construct(cur-1,0,val,val+1);
                construct(n-cur,0,val,val+cur);
            }
            else if(cur+cur/2 < n)
            {
                construct(cur-1,0,val,val+1);
                construct(n-cur,1,val,val+cur);
            }
            else
            {
                cur/=2;
                construct(cur-1,0,val,val+1);
                construct(n-cur,tar,val,val+cur);
            }
        }
    }
}

int main()
{
    int i,j,k,l;
    v[1][0] = true;
    v[3][0] = true;
    for(i=4; i<N; i++)
    {
        if( i%2 == 1 )
        {
            for(j=1; j<i; j++)
            {
                if(j%2==1)
                {
                    for(k=0; k<N; k++)
                        for(l=0; l<N; l++)
                            if(v[j][k] && v[i-j-1][l])
                            {
                                if(j>2*(i-j-1) || (i-j-1) > 2*j)
                                    v[i][k+l+1] = true;
                                else
                                    v[i][k+l] = true;
                            }
                }
            }
        }
    }
    cin>>n>>k;
    if(n%2==0)
        cout<<"NO\n";
    else if(n>=11)
    {
        int cur = n+1;
        int powe = 1;
        while(cur%2==0)
        {
            cur/=2;
            powe*=2;
        }
        if(k>(n-3)/2)
            cout<<"NO\n";
        else if(powe == n+1 && k==1)
            cout<<"NO\n";
        else if(powe!=n+1 && k==0)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            construct(n,k,0,1);
        }
    }
    else
    {
        if(v[n][k])
        {
            cout<<"YES\n";
            construct(n,k,0,1);
        }
        else
            cout<<"NO\n";
    }
    return chtholly;
}
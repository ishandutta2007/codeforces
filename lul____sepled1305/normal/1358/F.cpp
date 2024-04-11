/*It's time for visitor to fall down. Let's me beat first 2700 problem!!!*/
#include<bits/stdc++.h>
using namespace std;
long long n,i,j,ans,ansb;
long long max_turn;
vector<long long> A,B;
vector<long long> ori_A,ori_B;

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        long long a;
        cin>>a;
        A.push_back(a);
        ori_A.push_back(a);
    }
    for(i=0;i<n;i++)
    {
        long long a;
        cin>>a;
        B.push_back(a);
        ori_B.push_back(a);
    }
    if(n==2)
    {
        if(A[0]>A[1])
        {
            swap(A[0],A[1]);
            ans++;
        }
        while(min(B[0],B[1])>A[0])
        {
            if(B[0]>B[1])
            {
                swap(B[0],B[1]);
                ans++;
            }
            ansb+=B[1]/B[0];
            B[1] = B[1]%B[0];
        }
        if(min(B[0],B[1]) < A[1] && max(B[0],B[1]) == A[0] && A[1]%A[0] == min(B[0],B[1]))
        {
            ansb-=(A[1]-min(B[0],B[1]))/A[0];
        }
        if(min(B[0],B[1]) == A[0] && A[1]%A[0]==max(B[0],B[1])%A[0])
        {
            if(B[0]>B[1])
            {
                swap(B[0],B[1]);
                ans++;
            }
            ansb+=(B[1]-A[1])/A[0];
            B[1] = A[1];
        }
        if(A[0]!=min(B[0],B[1]) || A[1]!=max(B[0],B[1]))
            cout<<"Impossible";
        else if(ansb>2e5)
        {
            cout<<"BIG\n";
            cout<<ansb;
        }
        else
        {
            cout<<"Small\n";
            cout<<ans+ansb<<"\n";
            deque<char> prin;
            bool swa = false;
            long long a=ori_A[0],b=ori_A[1],c=ori_B[0],d=ori_B[1];
            if(a>b)
            {
                swap(a,b);
                swa = true;
            }
            if(c>d)
            {
                swap(c,d);
                prin.push_back('R');
            }
            while(c!=a)
            {
                for(i=0;i<d/c;i++)
                    prin.push_front('P');
                d%=c;
                swap(c,d);
                prin.push_front('R');
            }
            while(d!=b)
            {
                prin.push_front('P');
                d-=c;
            }
            if(swa)
                prin.push_front('R');

            while(!prin.empty())
            {
                char k = prin.front();
                prin.pop_front();
                cout<<k;
            }
        }
    }
    else if(n>2)
    {
        string prin;
        bool pass = false;
        while(true)
        {
            bool cor = true;
            bool reverse_cor = true;
            for(i=0;i<n;i++)
            {
                if(B[i]!=A[i])
                    cor = false;
                if(B[n-1-i]!=A[i])
                    reverse_cor = false;
            }
            if(cor)
            {
                pass = true;
                break;
            }
            if(reverse_cor)
            {
                pass = true;
                prin.push_back('R');
                ans++;
                break;
            }
            bool cur_pass = true;
            bool checki = (B[1] > B[0]);
            if(checki)
            {
                for(i=2;i<n;i++)
                    if(B[i] <= B[i-1])
                        cur_pass = false;
                if(cur_pass)
                {
                    for(i=n-1;i>0;i--)
                        B[i] = B[i]-B[i-1];
                    ansb++;
                    if(ansb<=2e5)
                        prin.push_back('P');
                }
                else
                    break;
            }
            else
            {
                for(i=2;i<n;i++)
                    if(B[i] >= B[i-1])
                        cur_pass = false;
                if(cur_pass)
                {
                    for(i=0;i<n/2;i++)
                        swap(B[i],B[n-1-i]);
                    ans++;
                    if(ansb<=2e5)
                        prin.push_back('R');
                }
                else
                    break;
            }
        }
        if(!pass)
            cout<<"Impossible";
        else if (ansb>2e5)
            cout<<"Big\n"<<ansb;
        else
        {
            cout<<"Small\n"<<ansb+ans<<"\n";
            while(!prin.empty())
            {
                char k = prin.back();
                prin.pop_back();
                cout<<k;
            }
        }
    }
    else
    {
        if(A[0]!=B[0])
            cout<<"Impossible";
        else
            cout<<"Small\n0";
    }
    return 0;
}
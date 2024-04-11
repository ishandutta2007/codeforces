#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const long long INF = 2e18;
int n,k,A,B,i,j;
long long a[N];
long long powe[31];

bool left_check(int left, int t)
{
    return a[left] < t;
}

long long left_b_search(int tar)
{
    long long mini = 0;
    long long maxi = k+1;
    while(mini<maxi)
    {
        long long mid = mini +maxi >> 1;
        if(mini == mid)
        {
            if(left_check(maxi,tar))
                mini = maxi;
            else
                maxi = mini;
        }
        else
        {
            if(left_check(mid,tar))
                mini = mid;
            else
                maxi = mid;
        }
    }
    return mini;
}

bool right_check(int right, int t)
{
    return a[right] > t;
}

long long right_b_search(int tar)
{
    long long mini = 0;
    long long maxi = k+1;
    while(mini<maxi)
    {
        //cout<<mini<<" "<<maxi<<"\n";
        long long mid = mini +maxi >> 1;
        if(mini == mid)
        {
            if(right_check(mini,tar))
                maxi = mini;
            else
                mini = maxi;
        }
        else
        {
            if(right_check(mid,tar))
                maxi = mid;
            else
                mini = mid;
        }
    }
    return mini;
}

long long solve(int n,long long left,long long right)
{
    long long sum = INF;
    long long cur_sum;
    long long left_ans = left_b_search(left);
    long long right_ans = right_b_search(right);
    long long avg = right_ans - left_ans - 1;
    if(avg == 0)
        sum = A;
    else
    {
        if(right-left > 1e8)
            cur_sum = INF;
        else
            cur_sum = B*avg*(right-left+1);
        long long mid = left+right>>1;
        if(n>=1)
        {
            sum = solve(n-1,left,mid);
            sum += solve(n-1,mid+1,right);
        }
        sum = min(sum,cur_sum);
    }
    return sum;
}

int main()
{
    cin>>n>>k>>A>>B;
    for(i=0; i<k; i++)
    {
        cin>>a[i+1];
    }
    a[0] = -1;
    a[k+1] = 2e18;
    sort(a,a+k+2);
    powe[0] = 1;
    for(i=1; i<=30; i++)
        powe[i] = powe[i-1]*2;
    cout<<solve(n,1,powe[n]);
    return 0;
}
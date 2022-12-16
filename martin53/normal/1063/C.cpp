#include<bits/stdc++.h>
using namespace std;
const int inf=1e9,CO=inf/2;
bool ask(int x,int y)
{
    cout<<x<<" "<<y<<endl;
    cout.flush();
    string now;
    cin>>now;
    return now=="black";
}
void print(int x,int y)
{
    cout<<x<<" "<<CO-1<<" "<<x+1<<" "<<CO+1<<endl;
    exit(0);
}

int now;

void run(int x,int y,int n_)
{
    if(n_==0)print(x,y);
    int av=(x+y)/2;
    if(ask(av,CO)==now)run(av,y,n_-1);
    else run(x,av,n_-1);
}
int main()
{
int n;
cin>>n;

now=ask(0,CO);

n--;

int x=0,y=inf;

while(n)
{
    n--;
    int av=(x+y)/2;
    int a=ask(av,CO);
    if(a!=now)
    {
    y=av;
    break;
    }
    x=av;
}

run(x,y,n);


return 0;
}
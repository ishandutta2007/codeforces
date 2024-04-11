#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n;
vector<int> output;
int id;
struct info
{
    int a,b,id;
};
info inp[nmax];
info actual[nmax];
bool cmp(info a,info b)
{
    return a.a>b.a;
}
bool cmp2(info a,info b)
{
    return a.b<b.b;
}
void solve_up()
{
    id=0;
    for(int i=1;i<=n;i++)
        if(inp[i].a<inp[i].b)
        {
            id++;
            actual[id]=inp[i];
        }

    if(id==0)return;

    sort(actual+1,actual+id+1,cmp);
    /*
    cout<<"actual: "<<endl;
    for(int i=1;i<=id;i++)
    {
        cout<<actual[i].a<<" "<<actual[i].b<<endl;
    }
    */
    vector<int> now={};

    for(int i=1;i<=id;i++)
        now.push_back(actual[i].id);

    if(output.size()<now.size())
    {
        output=now;
    }
}

void solve_down()
{
    id=0;
    for(int i=1;i<=n;i++)
        if(inp[i].a>inp[i].b)
        {
            id++;
            actual[id]=inp[i];
        }

    if(id==0)return;

    sort(actual+1,actual+id+1,cmp2);
    /*
    cout<<"actual: "<<endl;
    for(int i=1;i<=id;i++)
    {
        cout<<actual[i].a<<" "<<actual[i].b<<endl;
    }
    */
    vector<int> now={};

    for(int i=1;i<=id;i++)
        now.push_back(actual[i].id);

    if(output.size()<now.size())
    {
        output=now;
    }
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
    scanf("%i%i",&inp[i].a,&inp[i].b);
    inp[i].id=i;
}

solve_up();

solve_down();

printf("%i\n",output.size());
for(auto k:output)printf("%i ",k);printf("\n");
return 0;
}
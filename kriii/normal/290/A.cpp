#include <stdio.h>
#include <string>

std::string P[41] = {""
    ,"Washington","Adams","Jefferson","Madison","Monroe","Adams",
    "Jackson","Van Buren","Harrison","Tyler","Polk","Taylor","Fillmore",
    "Pierce","Buchanan","Lincoln","Johnson","Grant","Hayes","Garfield",
    "Arthur","Cleveland","Harrison","Cleveland","McKinley","Roosevelt","Taft",
    "Wilson","Harding","Coolidge","Hoover","Roosevelt","Truman","Eisenhower","Kennedy",
    "Johnson","Nixon","Ford","Carter","Reagan"};

int main()
{
    int x;

    scanf ("%d",&x);
    printf ("%s",P[x].c_str());
    return 0;
}
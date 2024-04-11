#include <cstdio>
#include <vector>
#include <string>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

int n;
vector <string> words;
char tmp[10];
int pnt;

bool checkPair()
{
	if (pnt == words.size()) return false;
	if (pnt < words.size() && words[pnt++] == "pair" && !checkPair()) return false;
	if (pnt == words.size()) return false;
	if (pnt < words.size() && words[pnt++] == "pair" && !checkPair()) return false;
	return true;
}

bool Check()
{
	if (pnt < words.size() && words[pnt++] == "pair" && !checkPair()) return false; 
	if (pnt < words.size()) return false;
	return true;
}

void printPair()
{
	printf("pair<");
	if (words[pnt++] == "pair") printPair();
	else printf("int");
	printf(",");
	if (words[pnt++] == "pair") printPair();
	else printf("int");
	printf(">");
}

void Print()
{
	if (words[pnt++] == "pair") printPair();
	else printf("int");
	printf("\n");
}

int main()
{
	scanf("%d", &n);
	while (scanf("%s", tmp) == 1) words.push_back(tmp);
	if (Check()) { pnt = 0; Print(); }
	else printf("Error occurred\n");
	return 0;
}
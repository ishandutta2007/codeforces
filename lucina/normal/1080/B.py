q=(int)(input())
for tt in range(q) :
    l, r = map(int, input().split())
    print(r//2-((r%2)*r)-((l-1)//2-((l-1)%2*(l-1))))
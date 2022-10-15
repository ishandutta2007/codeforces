n = int(input())
cards = list(map(int, input().split()))
ans = []
for step in range(n):
    for i in range(1, n + 1):
        if i == n:
            print(len(ans))
            for p in ans:
                segments = [p[0], p[1] - p[0], p[2] - p[1], n - p[2]]
                print(4 - segments.count(0), end=' ')
                for e in segments:
                    if (e != 0):
                        print(e, end=' ')
                print()
            exit()
        if (cards.index(i) > cards.index(i + 1)):
            for j in range(cards.index(i + 1), n + 1):
                if (j == n) or (j - cards.index(i + 1) != cards[j] - i - 1):
                    ans.append([cards.index(i + 1), j, cards.index(i)+1])
                    cards = cards[cards.index(i)+1:] + cards[j:cards.index(i)+1] + cards[cards.index(i + 1):j] + cards[:cards.index(i + 1)]
                    break
            break
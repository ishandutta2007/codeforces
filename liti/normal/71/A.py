def solve(word: str):
    if len(word) <= 10:
        return word
    else:
        return word[0] + str(len(word)-2) + word[-1]
    return word

n = int(input())

for i in range(n):
    word = input()
    print(solve(word))
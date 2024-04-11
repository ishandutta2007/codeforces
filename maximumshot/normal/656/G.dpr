var
i, j, F, o, T, res, kitten : integer;
c : array[1..10] of integer;
s : string;
begin
read(F); read(o); readln(T);
for i := 1 to o do c[i]:=0;
for i := 1 to F do begin
readln(s);
    for j := 1 to o do 
        if s[j] = 'Y' then inc(c[j]);
end;
res := 0;
for i := 1 to o do
    if c[i] >= T then inc(res);
write(res);
end.
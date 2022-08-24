program pp;
var
x, p, q, cnt, i : integer;
begin
read(x);
for i := 1 to x do
        begin
                readln(p, q);
                if (p + 2 <= q) then
                        inc(cnt);
        end;

writeln(cnt);
end.
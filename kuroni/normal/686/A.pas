var str: char;
    n, i, rip: longint;
    x, d: int64;

begin
  read(n);
  readln(x);
  for i := 1 to n do
  begin
    read(str);
    readln(d);
    if str = '+' then inc(x,d)
    else if x >= d then dec(x,d) else inc(rip);
  end;
  write(x,' ',rip);
end.
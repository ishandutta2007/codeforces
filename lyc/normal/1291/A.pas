var n,i,t,t1,i1:longint;b:array[0..1]of longint;st:ansistring;
begin
  readln(t1);
  for i1:=1 to t1 do
  begin
  b[0]:=0;b[1]:=0;
  readln(n);
  readln(st);
  for i:=1 to n do
  begin
    t:=ord(st[i])-ord('0');
    inc(b[t mod 2]);
  end;
  if b[1]<2 then writeln(-1)
  else
  begin
    t:=0;
    for i:=1 to n do
      if ord(st[i]) mod 2=1 then
      begin
        write(st[i]);
        inc(T);
        if t=2 then break;
      end;
    writeln;
  end;
  end;
end.
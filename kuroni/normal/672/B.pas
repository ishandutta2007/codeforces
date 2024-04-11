var n,i,cnt:longint;
    str: ansistring;
begin
  readln(n);
  readln(str);
  if n > 26 then write('-1') else
  begin
    for i := 97 to 122 do if pos(chr(i),str) > 0 then inc(cnt);
    write(n-cnt);
  end;
end.
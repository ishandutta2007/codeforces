const
  a:array[1..15] of integer=(2,3,5,7,11,13,17,19,23,29,31,37,41,43,47);
var
  x,c:integer;
  s:string;
begin
  c:=0;
  for x:=1 to 15 do
  begin
    writeln(a[x]);
    flush(output);
    readln(s);
    if(s[1]='y')then
    begin
      c:=c+1;
      if(c>=2)then begin writeln('composite');exit;end;
      if(a[x]*a[x]<=100)then
      begin
        writeln(a[x]*a[x]);
        flush(output);
        readln(s);
        if(s[1]='y')then
        begin
          c:=c+1;
          if(c>=2)then begin writeln('composite');exit;end;
        end;
      end;
    end;
  end;
  writeln('prime');
  flush(output);
end.
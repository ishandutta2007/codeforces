var str, a, d: ansistring;
    b, i: longint;

begin
  readln(str);
  a := copy(str,1,pos('.',str)-1);
  d := copy(str,pos('.',str)+1,pos('e',str)-pos('.',str)-1);
  val(copy(str,pos('e',str)+1,length(str)-pos('e',str)),b);
  for i := 1 to b do
  begin
    if length(d) = 0 then a := a + '0' else
    begin
      a := a + d[1];
      d := copy(d,2,length(d)-1);
    end;
  end;
  if (d = '0') or (length(d) = 0) then write(a) else write(a,'.',d);
end.
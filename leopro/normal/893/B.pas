program project1;

var
  N, divider, i, divid: LongInt;

 function Power2(a, b: LongInt): LongInt;
 var
   j: LongInt;
 begin
   Result := 1;
   For j := 1 to b do Result := Result * a;
 end;

begin
  Readln(N);
  divider := 1;
  divid := 1;
  For i := 1 to N do
  begin
    divider :=  (Power2(2, i) - 1) * Power2(2, i - 1);
    If N mod divider = 0 then divid := divider;
    If divider > N then break;
  end;
  WriteLn(divid);
end.
var n,h,otv,l,ost,k:int64;
    i:longint;
begin
    read(n,h,k);
    for i:=1 to n do begin
        read(l);
        if ost+l<=h then begin
            ost:=ost+l;
            otv:=otv+ost div k;
            ost:=ost mod k;
        end
    else begin
        inc(otv);
        ost:=l;
        otv:=otv+ost div k;
        ost:=ost mod k;
        end;
    end;
    write(otv+ord(ost>0));
end.